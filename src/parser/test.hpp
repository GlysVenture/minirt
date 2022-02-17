#ifndef DEFAULT_HPP
# define DEFAULT_HPP

#include <iostream>

class default
{
	private:
		std::string name;
	public:
		default(const default& t);
		default(std::string n_name);
		default(void);
		default&	operator=(const default& t);
		~default(void);
};
#endif
