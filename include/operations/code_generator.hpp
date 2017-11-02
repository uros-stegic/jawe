#ifndef __CODE_GENERATOR_HPP__
#define __CODE_GENERATOR_HPP__

#include <vector>
#include <map>

#include <operations/basic_operation.hpp>
#include <syntax.hpp>
#include <llvm/IR/IRBuilder.h>
#include <utils/scope.hpp>

namespace jawe {

/** \brief Operation pass that creates LLVM IR code.
 *
 */
class code_generator : public basic_operation {
public:
	code_generator();
	void run();
private:
	llvm::Value* codegen(const shared_node&);

	llvm::IRBuilder<> m_ir_builder;
	utils::scope<llvm::AllocaInst*> m_scopes;

	llvm::AllocaInst* create_alloca(llvm::Function*, const char*) const;

};
}

#endif // __CODE_GENERATOR_HPP__
