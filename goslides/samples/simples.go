func TestValidFirstNode(t *testing.T) {
    New("select * from users")
    ast, _ := AST()

    if ast.Child == nil {
        t.Errorf("Program is empty")
    }
}