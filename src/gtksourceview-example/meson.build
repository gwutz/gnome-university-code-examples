project('gucodeviewer', 'c',
  version : '0.1',
  default_options : ['warning_level=3'])

executable('gucodeviewer',
           'gucodeviewer.c',
           'main.c',
           dependencies: [
             dependency('gtk+-3.0'),
             dependency('gtksourceview-4')
           ],
           install : true)
