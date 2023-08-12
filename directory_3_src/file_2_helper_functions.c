#include <gtk/gtk.h>
#include "file_1_constants.h"
#include "header_file_1_structs.h"

void widget_size_allocate_scaling_callback(GtkWidget * widget, GdkRectangle * allocation, gpointer user_data) {
    Gtk_widget_with_scaling * scaling_widget = (Gtk_widget_with_scaling *) user_data;
    //g_print("Allocated : %d\n", allocation->width);
    //g_print("Allocated : %d\n", allocation->height);
    //g_print("Allocated start: %d\n", (int) (scaling_widget->margin_start_scale * allocation->width));
    //g_print("Allocated end: %d\n", (int) (scaling_widget->margin_end_scale * allocation->width));
    //g_print("Allocated top: %d\n", (int) (scaling_widget->margin_top_scale * allocation->height));
    //g_print("Allocated bottom: %d\n-----------\n", (int) (scaling_widget->margin_bottom_scale * allocation->height));

    gtk_widget_set_margin_start(scaling_widget->widget, (int) (scaling_widget->margin_start_scale * allocation->width));
    gtk_widget_set_margin_end(scaling_widget->widget, (int) (scaling_widget->margin_end_scale * allocation->width));
    gtk_widget_set_margin_top(scaling_widget->widget, (int) (scaling_widget->margin_top_scale * allocation->height));
    gtk_widget_set_margin_bottom(scaling_widget->widget, (int) (scaling_widget->margin_bottom_scale * allocation->height));
}

void setup_dynamic_resizing_for_widget (Gtk_widget_with_scaling * scaling_widget){
    scaling_widget->margin_start_scale = ((double) gtk_widget_get_margin_start(scaling_widget->widget)) / DEFAULT_WIDTH;
    scaling_widget->margin_end_scale = ((double) gtk_widget_get_margin_end(scaling_widget->widget)) / DEFAULT_WIDTH;
    scaling_widget->margin_top_scale = ((double) gtk_widget_get_margin_top(scaling_widget->widget)) / DEFAULT_HEIGHT;
    scaling_widget->margin_bottom_scale = ((double) gtk_widget_get_margin_bottom(scaling_widget->widget)) / DEFAULT_HEIGHT;
    g_signal_connect(G_OBJECT(gtk_widget_get_parent(scaling_widget->widget)), "size-allocate", G_CALLBACK(widget_size_allocate_scaling_callback), scaling_widget);
}