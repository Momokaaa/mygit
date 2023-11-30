call plug#begin('~/.vim/plugged')
Plug 'morhetz/gruvbox'
Plug 'scrooloose/nerdtree'
call plug#end()
	
se sw=4 sts=4 et nu sc hls rnu
set backspace=2
set smartindent
set mouse=a
map <F10> :NERDTreeToggle<CR>
vnoremap <C-y> "+y
colorscheme gruvbox
autocmd BufNewFile *.cpp 0r ~/.vim/templates/cpptemp.cpp | let @d = strftime("%Y.%m.%d %H:%M:%S") | execute '1,$s/%DATE%/' . @d . '/'
