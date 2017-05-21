#include <utils/reader.hpp>
#include <utils/control.hpp>

using namespace jawe;

Reader::Reader(std::string filename)
	: m_current_line(0)
	, m_current_char(0)
	, m_input(std::ifstream(filename))
{}

Reader::~Reader()
{
	m_input.close();
}

Reader& Reader::get_reader()
{
	std::string filename = Control::get().input_filename();
	static Reader instance(filename);
	return instance;
}

int Reader::read(char* buffer)
{
	char buf = pop_char();
	if( buf == 0 ) {
		return 0;
	}
	*buffer = buf;
	return 1;
}

std::string Reader::get_line(int line_no) const
{
	return m_archive[line_no];
}
int Reader::get_line() const
{
	return m_current_line;
}
int Reader::get_position() const
{
	return m_current_char;
}
std::string Reader::get_buffer() const
{
	return m_internal_buffer;
}

char Reader::pop_char()
{
	if( m_current_char >= m_internal_buffer.size() ) {
		if( std::getline(m_input, m_internal_buffer) ) {
			m_current_char = 0;
			m_current_line++;
			m_archive.push_back(m_internal_buffer);
			return pop_char();
		}
		else {
			return 0;
		}
	}
	return m_internal_buffer[m_current_char++];
}

