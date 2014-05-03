// s é a AST maluca!
where := s.Where
rows := make([]tableRow, s.Limit)
fn := func(commit *git.Commit) bool {
    builder.setCommit(commit) // OMIT
    boolRegister = true
    visitor.VisitExpr(where)
    // o resultado do where é true? 
    if boolRegister {
        newRow := make(tableRow)
        // fields é um array com todos os campos (ex: [author, hash]) 
        for _, f := range fields {
            // metadatacommit pega o valor real do commit representado pelo campo f
            newRow[f] = metadataCommit(f, commit) 
        }
        // guardando as linhas de sucesso
        rows = append(rows, newRow)

        counter = counter + 1
    }
    if counter > s.Limit {
        return false
    }
    return true
}