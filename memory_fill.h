/*!
    \file
    File with the function, what fill memory in struct onegin
*/

#ifndef MEMORY_FILL_H
#define MEMORY_FILL_H

#include <sys/stat.h>
#include <stdlib.h>

#include "my_assert.h"
#include "struct_text.h"

/*!
    The function what fill full information about text, what already read
    \param [out]  onegin_ptr - the pointer on struct with info about Onegin
*/
size_t onegin_info_fill(Text *onegin_ptr);

#endif // MEMORY_FILL_H