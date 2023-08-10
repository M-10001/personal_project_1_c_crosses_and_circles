#include <gtk/gtk.h>
#include "file_1_constants.h"

void setup_dynamic_resizing_for_widget (GtkWidget * widget){
    double scaling = ((double) gtk_widget_get_margin_start(widget)) / DEFAULT_WIDTH;
    g_object_set_data(G_OBJECT(widget), KEY_1_WIDGET_MARGIN_START_SCALING, GINT_TO_POINTER(scaling));
    
    scaling = ((double) gtk_widget_get_margin_end(widget)) / DEFAULT_WIDTH;
    g_object_set_data(G_OBJECT(widget), KEY_2_WIDGET_MARGIN_END_SCALING, GINT_TO_POINTER(scaling));

    scaling = ((double) gtk_widget_get_margin_top(widget)) / DEFAULT_HEIGHT;
    g_object_set_data(G_OBJECT(widget), KEY_3_WIDGET_MARGIN_TOP_SCALING, GINT_TO_POINTER(scaling));
    
    scaling = ((double) gtk_widget_get_margin_bottom(widget)) / DEFAULT_HEIGHT;
    g_object_set_data(G_OBJECT(widget), KEY_4_WIDGET_MARGIN_BOTTOM_SCALING, GINT_TO_POINTER(scaling));
}
