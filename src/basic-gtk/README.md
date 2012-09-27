Basic Gtk Samples
=================

basic.c
-------

```bash
$ gcc basic.c -o basic `pkg-config --cflags --libs gtk+-3.0`
```

![](https://raw.github.com/Wutzara/gnome-university-code-examples/master/src/basic-gtk/images/basic.png)

basic_clipboard.c
-----------------

```bash
$ gcc basic_clipboard.c -o basic-clipboard `pkg-config --cflags --libs gtk+-3.0`
```

![](https://raw.github.com/Wutzara/gnome-university-code-examples/master/src/basic-gtk/images/basic-clipboard.png)

sync.c sync_window.h sync_window.c
----------------------------------

```bash
$ gcc sync.c sync_window.h sync_window.c -o sync `pkg-config --cflags --libs gtk+-3.0`
```

![](https://raw.github.com/Wutzara/gnome-university-code-examples/master/src/basic-gtk/images/sync.png)

textfileviewer.c text_window.h text_window.c
--------------------------------------------

```bash
$ gcc textfileviewer.c text_window.c text_window.h -o text `pkg-config --cflags --libs gtk+-3.0`
```

![](https://raw.github.com/Wutzara/gnome-university-code-examples/master/src/basic-gtk/images/text_file_viewer.png)
