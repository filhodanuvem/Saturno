require 'gtk2'

module Gtk_grafo

	def self.gera_janela(nome_arquivo)
		window = Gtk::Window.new
		window.resizable = true
		textview = Gtk::TextView.new

		grafo_image = Gdk::Pixbuf.new("#{nome_arquivo}.png")
		iter = textview.buffer.get_iter_at_line(0)
		textview.buffer.insert_pixbuf(iter, grafo_image)

		infos = Gdk::Pixbuf.get_file_info("#{nome_arquivo}.png")
		window.set_size_request(infos[1] + 60, infos[2] + 30)
		scrolled_win = Gtk::ScrolledWindow.new
		scrolled_win.border_width = 5
		scrolled_win.add(textview)
		scrolled_win.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_ALWAYS)
		window.add(scrolled_win)
		window.title = "Grafo"
		window.show_all
		Gtk.main
	end
end 
