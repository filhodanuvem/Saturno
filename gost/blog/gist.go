package blog

type GistCollector struct {
}

func (g GistCollector) New() *GistCollector {
	gist := new(GistCollector)
	gist.connect()

	return gist
}

func (gist *GistCollector) FindPosts() ([]Post, error) {
	return nil, nil
}

func (gist *GistCollector) connect() {

}
