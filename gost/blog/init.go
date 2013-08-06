package blog

import (
	"time"
)

type Collector interface {
	show(post *Post) (string, error)
	FindPosts() ([]Post, error)
}

type Author struct {
	id   int
	name string
}

type Post struct {
	title      string
	author     *Author
	body       string
	created_at time.Time
}
