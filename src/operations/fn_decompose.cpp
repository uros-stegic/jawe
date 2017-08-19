#include <operations/fn_decompose.hpp>
#include <syntax.hpp>
#include <lang.syn.hpp>

using namespace jawe;

extern shared_node* program;

void FunctionDecomposer::decompose(shared_node* root) const
{
}

void FunctionDecomposer::run() const
{
	decompose(program);
}
