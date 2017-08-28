#ifndef __CONTROL_HPP__
#define __CONTROL_HPP__

#include <string>
#include <memory>

#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>

#include <llvm/IR/Module.h>

namespace jawe {
class control {
public:
	control(const control&) = delete;
	void operator=(const control&) = delete;

	static control& get(int = 0, char ** = nullptr);
	std::string input_filename() const;
	bool dump_ast() const;
	bool dump_program() const;
	bool show_memory() const;
	bool check_leaks() const;

	void run() const;
	llvm::LLVMContext& get_context();
	std::unique_ptr<llvm::Module>& get_module();

private:
	int m_argc;
	char **m_argv;
	boost::program_options::options_description m_desc;
	boost::program_options::variables_map m_vars;
	std::string m_input;
	std::string m_output;
	bool m_dump_ast;
	bool m_dump_program;
	bool m_show_memory;
	bool m_check_leaks;

	/* LLVM stuff */
	llvm::LLVMContext m_context;
	std::unique_ptr<llvm::Module> m_module;

	control(int, char **);
	void m_print_help() const;
	void m_print_version() const;

};
}

#endif // __CONTROL_HPP__
