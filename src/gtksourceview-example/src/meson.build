gnome = import('gnome')

resources = gnome.compile_resources(
  'gucodeviewer resources',
  'gucodeviewer.gresource.xml',
  source_dir: '.'
)

executable('gucodeviewer',
           'main.c',
           'gucodeviewerapp.c',
           'gucodeviewerappwindow.c',
           resources,
           dependencies: [
             dependency('gtk+-3.0'),
             dependency('gtksourceview-4')
           ],
           install : true)
