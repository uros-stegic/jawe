#ifndef __CONTROL_HPP__
#define __CONTROL_HPP__

#include <string>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>

namespace jawe {
class Control {
public:
	Control(const Control&) = delete;
	void operator=(const Control&) = delete;

	static Control& get(int = 0, char ** = nullptr);
	std::string input_filename() const;
	bool dump_ast() const;
	bool dump_program() const;
	bool show_memory() const;

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
	bool m_show_memory;
	
	Control(int, char **);
	void m_print_help() const;
	void m_print_version() const;
};
}

#endif // __CONTROL_HPP__

