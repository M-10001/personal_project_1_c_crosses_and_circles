#include <gtk/gtk.h>
#include "file_1_constants.h"
#include "header_file_1_structs.h"

void widget_size_allocate_callback(GtkWidget * widget, GdkRectangle * allocation, gpointer user_data) {
    GtkWindow * parent_window = GTK_WINDOW(widget);
    Gtk_custom_widget_1 * custom_widget = (Gtk_custom_widget_1 *) user_data;

    int margin_start = (int) (custom_widget->margin_start_scale * allocation->width);
    int margin_end = (int) (custom_widget->margin_end_scale * allocation->width);
    int margin_top = (int) (custom_widget->margin_top_scale * allocation->height);
    int margin_bottom = (int) (custom_widget->margin_bottom_scale * allocation->height);
    
    if (gtk_window_is_maximized(parent_window) == true){
        custom_widget->previously_maximised = true;
    } else if (custom_widget->previously_maximised == true){
        margin_start = custom_widget->previous_margin_start;
        margin_end = custom_widget->previous_margin_end;
        margin_top = custom_widget->previous_margin_top;
        margin_bottom = custom_widget->previous_margin_bottom;
    } else {
        custom_widget->previous_margin_start = margin_start;
        custom_widget->previous_margin_end = margin_end;
        custom_widget->previous_margin_top = margin_top;
        custom_widget->previous_margin_bottom = margin_bottom;
        custom_widget->parent_window_previous_width = allocation->width;
        custom_widget->parent_window_previous_height = allocation->height;
    }

    gtk_widget_set_margin_start(custom_widget->widget, margin_start);
    gtk_widget_set_margin_end(custom_widget->widget, margin_end);
    gtk_widget_set_margin_top(custom_widget->widget, margin_top);
    gtk_widget_set_margin_bottom(custom_widget->widget, margin_bottom);

    if ((gtk_window_is_maximized(parent_window) == false) && (custom_widget->previously_maximised == true)){
        custom_widget->previously_maximised = false;
        gtk_window_resize(parent_window, custom_widget->parent_window_previous_width, custom_widget->parent_window_previous_height);
    }
}

void setup_dynamic_resizing_for_widget (Gtk_custom_widget_1 * custom_widget, GtkWindow * parent_window){
    custom_widget->margin_start_scale = ((double) gtk_widget_get_margin_start(custom_widget->widget)) / DEFAULT_WIDTH;
    custom_widget->margin_end_scale = ((double) gtk_widget_get_margin_end(custom_widget->widget)) / DEFAULT_WIDTH;
    custom_widget->margin_top_scale = ((double) gtk_widget_get_margin_top(custom_widget->widget)) / DEFAULT_HEIGHT;
    custom_widget->margin_bottom_scale = ((double) gtk_widget_get_margin_bottom(custom_widget->widget)) / DEFAULT_HEIGHT;
    g_signal_connect(G_OBJECT(parent_window), "size-allocate", G_CALLBACK(widget_size_allocate_callback), custom_widget);
}