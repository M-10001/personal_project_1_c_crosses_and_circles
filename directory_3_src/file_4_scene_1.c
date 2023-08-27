#include <gtk/gtk.h>
#include "file_1_constants.h"
#include "file_2_helper_functions.h"
#include "header_file_1_structs.h"

static GtkWindow * level_1_1_window;
static GtkStack * level_2_1_container;
static Gtk_custom_widget_1 level_4_1_scaling_button;

void load_scene_1 (GtkWindow * _level_1_1_window, GtkStack * _level_2_1_container){
    GtkBuilder * builder;
    GError *error = NULL;

    GtkWidget * level_3_1_container;

    level_1_1_window = _level_1_1_window;
    level_2_1_container = _level_2_1_container;

    builder = gtk_builder_new ();

    if (gtk_builder_add_from_file (builder, "directory_2_scenes/1.glade", &error) == 0){
        g_printerr ("Error loading file: %s\n", error->message);
        g_clear_error (&error);
        gtk_main_quit();
    }

    level_3_1_container = GTK_WIDGET(gtk_builder_get_object(builder, "level_3_1_container"));

    level_4_1_scaling_button.widget = GTK_WIDGET(gtk_builder_get_object(builder, "level_4_1_button"));
    setup_dynamic_resizing_for_widget(&level_4_1_scaling_button, level_1_1_window);

    gtk_container_add(GTK_CONTAINER(level_2_1_container), level_3_1_container);
    gtk_stack_set_visible_child(level_2_1_container, level_3_1_container);
}