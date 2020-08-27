--a list of paths to lua script modules
local paths={
    '{root}/{module}',
    '{root}/lib/{module}',
    '{root}/lib/external/{module}',
    '{root}/lib/external/platform-specific/{platform}/{module}',
}
print('paths= ' .. table.concat(paths,';'))
--a list of paths to binary lua modules
local module_paths={
    '?.{extension}',
    '?/init.{extension}',
    '?/core.{extension}',
}
print('module_paths= ' .. table.concat(module_paths,';'))
-- List of supported OS paired with binary file extension name
local extensions={
    Windows='dll',
    Linux='so',
    Mac='dylib',
}
-- os_name is a supplemental module for
-- OS and CPU architecture detection
--local os_name=require("os_name")
local os_name='Windows'
print('os_name---' .. os_name)
-- A dot character represent current working directory
local root_dir='.'
--local current_platform,current_architecture=os_name.getOS()
local current_platform,current_architecture=os_name,'x86_64'
local cpaths, lpaths = {}, {}
local current_clib_extension=extensions[current_platform]

--Keep in mind that you need to execute this code before any require command
if current_clib_extension then
    -- now you can process each defined path for module.
    for _, path in ipairs(paths) do
        local path = path:gsub("{(%w+)}", {
            root = root_dir,
            platform = current_platform,
        })
        print(path .. '\n---')
        -- skip empty path entries
        if #path>0 then
            -- make a substitution for each module file path.
            for _, raw_module_path in ipairs(module_paths) do
                local module_path = path:gsub("{(%w+)}", {
                    module = raw_module_path
                })
                -- add path for binary module
                cpaths[#cpaths+1] = module_path:gsub("{(%w+)}", {
                    extension = current_clib_extension
                })
                -- add paths for platform independent lua and luac modules
                lpaths[#lpaths+1] = module_path:gsub("{(%w+)}", {
                    extension = 'lua'
                })
                lpaths[#lpaths+1] = module_path:gsub("{(%w+)}", {
                    extension = 'luac'
                })
            end
        end
    end
    -- build module path list delimited with semicolon.
    package.path = table.concat(lpaths, ";")
    package.cpath = table.concat(cpaths, ";")
    --print(table.concat(lpaths,';'))
    --print('----------------')
    --print(table.concat(cpaths,';'))
end

local function ipairs_sparse(table_)
    -- tmpIndex will hold sorted indices, otherwise
    -- this iterator would be no different from pairs iterator
    table__={
        a=1,b=2,c=3
    }
    local index,value=next(table__)
    while index do
        print(index)
        print(value)
        index,value=next(table__,index)
    end
end

ipairs_sparse()
