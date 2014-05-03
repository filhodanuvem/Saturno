type NodeExpr interface {
    Assertion(lvalue, rvalue string) bool
}

func (n *NodeSmaller) Assertion(lvalue string, rvalue string) bool {
    time := ExtractDate(rvalue)
    if time != nil {
        timeFound := ExtractDate(lvalue)
        if timeFound != nil {
            return timeFound.Before(*time) || (n.Equal && timeFound.Equal(*time))
        }
    }
    return lvalue < rvalue
}