% for cls in class_list:
require "${cls}"
% endfor

function build()
% for cls in class_list:
    ${cls}.build()
% endfor
end

build()
