#ifndef __CONTROL_HPP__
#define __CONTROL_HPP__

#include <string>
#include <memory>

#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>

#include <llvm/IR/Module.h>

namespace jawe {

/** \brief Singleton class that manages the state of compiler.
 *
 * It' primarily purpose is to manage the state, run the steps, and to set the flags that are passed when running the
 * compiler. Also, it is the owner of LLVM module and context.
 */
class control {
public:
	/**
	 * Deleted copy constructor. Prevention against copying singleton instance.
	 */
	control(const control&) = delete;

	/**
	 * Deleted copy assignment operator. Prevention against copying singleton instance.
	 */
	void operator=(const control&) = delete;

	/** \brief Gets singleton instance.
	 *
	 * Command line arguments must be passed in order to construct the original instance.
	 * Once constructed, these arguments become obsolete, and should not be passed again.
	 * @param argc number of command line arguments.
	 * @param argv an array of strings (command line arguments)
	 */
	static control& get(int argc = 0, char** argv = nullptr);

	/**
	 * Gets the filename (path) of the input file.
	 */
	std::string input_filename() const;

	/**
	 * Checks if --dump-ast flag is passed.
	 */
	bool dump_ast() const;

	/**
	 * Checks if --dump-program flag is passed.
	 */
	bool dump_program() const;

	/**
	 * Checks if --dump-ir flag is passed.
	 */
	bool dump_ir() const;

	/**
	 * Checks if --show-memory flag is passed.
	 */
	bool show_memory() const;

	/**
	 * Checks if --check-leaks flag is passed.
	 */
	bool check_leaks() const;

	/**
	 * Gets LLVM context.
	 */
	llvm::LLVMContext& get_context();

	/**
	 * Gets pointer to LLVM module.
	 */
	std::unique_ptr<llvm::Module>& get_module();

	/**
	 * Starts all the phases of compiler.
	 */
	void run() const;

private:
	int m_argc;
	char **m_argv;
	boost::program_options::options_description m_desc;
	boost::program_options::variables_map m_vars;
	std::string m_input;
	std::string m_output;
	bool m_dump_ast;
	bool m_dump_program;
	bool m_dump_ir;
	bool m_show_memory;
	bool m_check_leaks;

	/* LLVM stuff */
	llvm::LLVMContext m_context;
	std::unique_ptr<llvm::Module> m_module;

	/** \brief Constructs control (singleton) instance.
	 *
	 * This constructor is used when first creating an instance. It accepts
	 * command line arguments so that they can be passed to boost::program_options
	 * library.
	 * @param argc number of command line arguments.
	 * @param argv an array of strings (command line arguments)
	 */
	control(int argc, char** argv);

	/**
	 * Prints help message (gets called if --help flag is set)
	 */
	void m_print_help() const;

	/**
	 * Prints version message (gets called if --version flag is set)
	 */
	void m_print_version() const;
};
}

#endif // __CONTROL_HPP__

