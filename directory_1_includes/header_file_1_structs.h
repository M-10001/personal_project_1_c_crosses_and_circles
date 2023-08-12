#pragma once
#include <gtk/gtk.h>

typedef struct Gtk_widget_with_scaling {
    GtkWidget * widget;
    double margin_start_scale;
    double margin_end_scale;
    double margin_top_scale;
    double margin_bottom_scale;
} Gtk_widget_with_scaling;