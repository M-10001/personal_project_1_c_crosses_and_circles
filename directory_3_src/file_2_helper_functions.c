#include <gtk/gtk.h>
#include "file_1_constants.h"
#include "header_file_1_structs.h"

void setup_dynamic_resizing_for_widget (Gtk_widget_with_scaling * scaling_widget){
    scaling_widget->margin_top_scale = ((double) gtk_widget_get_margin_start(scaling_widget->widget)) / DEFAULT_WIDTH;
    scaling_widget->margin_end_scale = ((double) gtk_widget_get_margin_end(scaling_widget->widget)) / DEFAULT_WIDTH;
    scaling_widget->margin_top_scale = ((double) gtk_widget_get_margin_top(scaling_widget->widget)) / DEFAULT_HEIGHT;
    scaling_widget->margin_bottom_scale = ((double) gtk_widget_get_margin_bottom(scaling_widget->widget)) / DEFAULT_HEIGHT;
}
