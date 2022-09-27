datadir = get_option('prefix') / get_option('datadir') / project_name
add_project_arguments('-DDATADIR="'+datadir+'"', language:'c')

install_data('gucodeviewer.ui', install_dir : datadir)

executable('gucodeviewer', 'main.c',
           dependencies: [
             dependency('gtk+-3.0'),
             dependency('gtksourceview-4')
           ],
           install : true)
