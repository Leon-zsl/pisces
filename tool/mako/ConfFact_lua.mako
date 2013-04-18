% for cls in class_list:
--require "${cls}"
% endfor

% for cls in class_list:
dofile(FPath_get_full_path_lua("${cls}.lua"))
% endfor

function build()
% for cls in class_list:
    ${cls}_build()
% endfor
end

build()
