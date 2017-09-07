#include <operations/assembly_generator.hpp>
#include <utils/control.hpp>

#include <iostream>
#include <system_error>

#include <llvm/Support/Host.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Support/TargetRegistry.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/Support/CodeGen.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/ADT/Optional.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/Support/raw_ostream.h>


using namespace jawe;

void assembly_generator::run() const
{
	auto target_triple = llvm::sys::getDefaultTargetTriple();

	llvm::InitializeAllTargetInfos();
	llvm::InitializeAllTargets();
	llvm::InitializeAllTargetMCs();
	llvm::InitializeAllAsmParsers();
	llvm::InitializeAllAsmPrinters();

	std::string error_msg;
	auto target = llvm::TargetRegistry::lookupTarget(target_triple, error_msg);

	if( !target ) {
  		std::cerr << error_msg << std::endl;
		std::exit(EXIT_FAILURE);
	}

	auto CPU = "generic";
	auto features = "";

	llvm::TargetOptions opt;
	auto RM = llvm::Optional<llvm::Reloc::Model>();
	auto target_machine = target->createTargetMachine(target_triple, CPU, features, opt, RM);

	control::get().get_module()->setDataLayout(target_machine->createDataLayout());
	control::get().get_module()->setTargetTriple(target_triple);

	auto filename = "a.out";
	std::error_code EC;
	llvm::raw_fd_ostream dest(filename, EC, llvm::sys::fs::F_None);

	if( EC ) {
  		std::cerr << "Could not open file: " << EC.message() << std::endl;
		std::exit(EXIT_FAILURE);
	}

	llvm::legacy::PassManager pass;
	auto file_t = llvm::TargetMachine::CGFT_ObjectFile;

	if( target_machine->addPassesToEmitFile(pass, dest, file_t) ) {
		std::cerr << "TargetMachine can't emit a file of this type" << std::endl;
		std::exit(EXIT_FAILURE);
	}

	pass.run(*(control::get().get_module()));
	dest.flush();
}
