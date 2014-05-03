package main // OMIT

import "github.com/libgit2/git2go" // OMIT
// import "github.com/libgit2/git2go" ... 

func main() { // OMIT
repo, _ := git2go.Open("/path/to/repository")
walk, _:= repo.Walk()

i := 1 
callback := func (oid *git.Commit) bool {
    fmt.Printf("\n%s\n", oid.Id())
    i = i + 1
    if i == 5 {
        return false
    }
    return true
}
err = walk.Iterate(callback)
if err != nil {
    fmt.Printf(err.Error())
}
} // OMIT