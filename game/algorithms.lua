function stack()
    local out = {}

    out.push = function(item)
        out[#item + 1] = item
    end

    out.pop = function()
        if #out > 0 then
            return table.remove(out, #out)
        end
    end

    out.iterator = function()
        return function()
            return out.pop()
        end
    end

    return out
end

function queue()
    local out = {}
    local head, tail = 0, -1

    out.push = function
    (item)
        tail = tail + 1
        out[tail] = item
    end

    out.pop = function
    ()
        if head <= tail then
            local value = out[head]
            out[head] = nil
            head = head + 1
            return value
        end
    end

    out.iterator = function
    ()
        return function
        ()
            return out.pop()
        end
    end

    setmetatable(out, { __len = function()
        return tail - head + 1
    end })
end

local remove_element_by_value = function
(table_, value_)
    for i = 1, #table_ do
        if table_[i] == value_ then
            table.remove(table_, i)
            break
        end
    end
end

function priority_queue()
    --interface table
    local table_ = {}
    --a set of elements
    local set = {}--{a=3}
    --a set of priority_bags with a elements
    local r_set = {}--{3={a,b,c}}
    --sorted list of priorities
    local priorities = {}
    -- add element into storage, set its priority and sort priorities
    -- k - element
    -- v - priority
    local function addKV(k, v)
        set[k] = v
        -- create a new list for this priority
        if not r_set[v] then
            table.insert(priorities, v)
            table.sort(priorities)
            local k0 = { k }
            r_set[v] = k0
            setmetatable(k0, { __mode = 'v' })
            -- add element into list for this priority
        else
            table.insert(r_set[v], k)
        end
    end
    -- remove element from storage and sort priorities
    local remove = function
    (k)
        local v = set(k)
        local priority_set = priorities[v]
        remove_element_by_value(priority_set, k)
        if #priority_set < 1 then
            remove_element_by_value(priorities, v)
            r_set[v] = nil
            table.sort(priorities)
            set[k] = nil
        end
    end
    table_.remove = remove
    -- returns an element with the lowest priority
    table_.min = function
    ()
        local min_priority = priorities[1]
        if min_priority then
            return r_set[min_priority][1] or {}
        else
            return {}
        end
    end
    -- returns an element with the highest priority
    table_.max = function
    ()
        local max_priority = priorities[#priorities]
        if max_priority then
            return r_set[max_priority][1] or {}
        else
            return {}
        end
    end
    -- is this queue empty?
    table_.empty = function
    ()
        return #priorities < 1
    end
    -- simple element iterator, retrieves elements with
    -- the highest priority first
    table_.iterator = function
    ()
        return function
        ()
            if not table_.empty then
                local k = table_.max
                table_.remove(k)
                return k
            end
        end
    end
    -- setup pqueue behavior
    setmetatable(tabel_, {
        __index = set,
        __newindex = function(table_, k, v)
            if not set[k] then
                addKV(k, v)
            else
                remove(k)
                addKV(k, v)
            end
        end
    })
    return table_
end

function ipairs_sparse(table_)
    local index_set = {}
    local index, _ = next(table_)

    while index do
        index_set[#index_set + 1] = index
        index, _ = next(table_, index)
    end
    -- sort table indices
    table.sort(index_set)
    local i = 1
    return function
    ()
        local i_ = index_set[i]
        i = i + 1
        if i_ then
            return i_, table_[i_]
        end
    end
end

local ipairs_sparse_test = function
()
    local t = {
        [10] = 'a', [2] = 'b', [5] = 'c', [100] = 'd', [99] = 'e',
    }
    for i, v in ipairs_sparse(t) do
        print(i, v)
    end
end
ipairs_sparse_test()

return {
    stack = stack,
    queue = queue,
    priority_queue = priority_queue
}
