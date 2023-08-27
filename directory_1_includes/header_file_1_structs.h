#pragma once
#include <stdbool.h>
#include <gtk/gtk.h>

typedef struct Gtk_custom_widget_1 {
    GtkWidget * widget;
    double margin_start_scale;
    double margin_end_scale;
    double margin_top_scale;
    double margin_bottom_scale;
    int previous_margin_start;
    int previous_margin_end;
    int previous_margin_top;
    int previous_margin_bottom;
    int parent_window_previous_width;
    int parent_window_previous_height;
    bool previously_maximised;
} Gtk_custom_widget_1;