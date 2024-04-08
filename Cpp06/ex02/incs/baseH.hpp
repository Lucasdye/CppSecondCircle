#ifndef BASEH_HPP
# define BASEH_HPP

//-------------------- Constants -------------------------------------------//
# ifndef SUC
#  define SUC 0
# endif

# ifndef ERR
#  define ERR -1
# endif
# ifndef FLOAT_MAX
#  define FLOAT_MAX 3.4028235e38f
# endif
# ifndef FLOAT_MIN
#  define FLOAT_MIN 1.17549435e-38f
# endif
# ifndef FLOAT_TRUE_MIN
#  define FLOAT_TRUE_MIN 1.40129846432481707e-45f
# endif

# ifndef DOUBLE_MAX
#  define DOUBLE_MAX 1.7976931348623157e+308
# endif

# ifndef DOUBLE_MIN
#  define DOUBLE_MIN 2.2250738585072014e-308
# endif

# ifndef DOUBLE_TRUE_MIN
#  define DOUBLE_TRUE_MIN 4.9406564584124654e-324
# endif
//-------------------- CPP libraries ----------------------------------------//
# include <iostream>
# include <sstream>
# include <unistd.h>
# include <string>
# include <cstdlib>
# include <iomanip>
# include <fstream>
# include <cmath>
# include <cstdlib>
# include <limits.h>
#include <cstdint>

//-------------------- Classes  ---------------------------------------------//
# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
//-------------------- Aesthetics -------------------------------------------//
# include "colors.hpp"
//-------------------- My funcs proto ---------------------------------------//
#endif 