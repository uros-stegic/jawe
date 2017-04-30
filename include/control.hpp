#ifndef __CONTROL_HPP__
#define __CONTROL_HPP__

#include <string>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>

namespace jawe {
class Control {
public:
	Control(int, char **);
	Control(const Control&) = delete;
	void operator=(const Control&) = delete;

	void run() const;

private:
	int m_argc;
	char **m_argv;
	boost::program_options::options_description m_desc;
	boost::program_options::variables_map m_vars;
	std::string m_input;
	std::string m_output;
	
	void m_print_help() const;
	void m_print_version() const;
};
}

#endif // __CONTROL_HPP__

