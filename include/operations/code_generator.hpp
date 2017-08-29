#ifndef __CODE_GENERATOR_HPP__
#define __CODE_GENERATOR_HPP__

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
};
}

#endif // __CODE_GENERATOR_HPP__

