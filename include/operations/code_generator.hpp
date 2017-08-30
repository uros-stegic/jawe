#ifndef __CODE_GENERATOR_HPP__
#define __CODE_GENERATOR_HPP__

#include <vector>
#include <map>

#include <operations/basic_operation.hpp>
#include <syntax.hpp>
#include <llvm/IR/IRBuilder.h>

namespace jawe {
class code_generator : public basic_operation {
public:
	code_generator();
	void run();
private:
	llvm::Value* codegen(const shared_node&);

	llvm::IRBuilder<> m_ir_builder;
	std::vector<std::map<std::string, llvm::AllocaInst*>> m_scopes;

	void open_scope();
	void close_scope();

	void push_variable(const std::string&, llvm::AllocaInst*);
	llvm::AllocaInst* find_variable(const std::string&) const;
	llvm::AllocaInst* create_alloca(llvm::Function*, const char*) const;

	void print_scopes() const;
};
}

#endif // __CODE_GENERATOR_HPP__

