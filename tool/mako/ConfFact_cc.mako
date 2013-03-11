% for cls in class_list:
#include "${cls}.h"
% endfor
#include "ConfFact.h"

void ConfFact::build()
{
    % for cls in class_list:
    ${cls}::build();
    % endfor
}

void ConfFact::destroy()
{
    % for cls in class_list:
    ${cls}::destroy();
    % endfor
}
