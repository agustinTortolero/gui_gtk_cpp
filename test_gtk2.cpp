#include <gtkmm.h>
#include<opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

#include <iostream>

using namespace cv;

/* este si funciona*/
/*
// Function to handle Sobel edge detection
void sobel_edge_detection() {
    // Load the image from file
    Mat image = imread("/home/agustin/Downloads/LenaMeyer.jpg", IMREAD_GRAYSCALE);

    if (image.empty()) {
        g_print("Error: Failed to load image.\n");
        return;
    }

    // Apply Sobel edge detection
    Mat edges;
    Sobel(image, edges, CV_8U, 1, 1);

    // Create a new window to display the edges
    namedWindow("Sobel Edges", WINDOW_NORMAL);
    imshow("Sobel Edges", edges);
    waitKey(0);
}

// Function to change the brightness of the image
void change_brightness(GdkPixbuf *pixbuf, int brightness_change) {
    // Get the width, height, and number of channels of the image
    int width = gdk_pixbuf_get_width(pixbuf);
    int height = gdk_pixbuf_get_height(pixbuf);
    int channels = gdk_pixbuf_get_n_channels(pixbuf);

    // Get the pixel data and rowstride
    guchar *pixels = gdk_pixbuf_get_pixels(pixbuf);
    int rowstride = gdk_pixbuf_get_rowstride(pixbuf);

    // Modify the brightness of each pixel
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int c = 0; c < channels; c++) {
                // Calculate the index of the current pixel
                int index = y * rowstride + x * channels + c;
                // Add the brightness_change value to the pixel value and clamp it to the range [0, 255]
                pixels[index] = CLAMP(pixels[index] + brightness_change, 0, 255);
            }
        }
    }
}

// Function to handle when the button is clicked
static void on_show_image_clicked(GtkWidget *button, gpointer data) {
    // Get the parent window
    GtkWidget *parent_window = (GtkWidget *)data;

    // Load the image from file into a pixbuf
    GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file("/home/agustin/Downloads/LenaMeyer.jpg", NULL);

    if (!pixbuf) {
        g_print("Error: Failed to load image.\n");
        return;
    }

    // Change the brightness of the image
    change_brightness(pixbuf, 100); // Change brightness by adding 100 to each pixel value

    // Create a new image from the modified pixbuf
    GtkWidget *image_widget = gtk_image_new_from_pixbuf(pixbuf);

    // Create a new window to display the modified image
    GtkWidget *image_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(image_window), "Modified Image");
    gtk_window_set_default_size(GTK_WINDOW(image_window), gdk_pixbuf_get_width(pixbuf), gdk_pixbuf_get_height(pixbuf));
    g_signal_connect(image_window, "destroy", G_CALLBACK(gtk_widget_destroy), NULL);

    // Add the image widget to the new window
    gtk_container_add(GTK_CONTAINER(image_window), image_widget);

    // Show all widgets in the new window
    gtk_widget_show_all(image_window);
}

// Function to handle when the Sobel edge detection button is clicked
static void on_sobel_edge_detection_clicked(GtkWidget *button, gpointer data) {
    // Perform Sobel edge detection
    sobel_edge_detection();
}

int main(int argc, char *argv[]) {
    // Initialize GTK
    gtk_init(&argc, &argv);

    // Create the main window
    GtkWidget *main_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(main_window), "Main Window");
    gtk_window_set_default_size(GTK_WINDOW(main_window), 200, 100);
    g_signal_connect(main_window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Create the "Show Image" button
    GtkWidget *show_image_button = gtk_button_new_with_label("Show Image");

    // Connect the "Show Image" button click signal to the callback function
    g_signal_connect(show_image_button, "clicked", G_CALLBACK(on_show_image_clicked), (gpointer)main_window);

    // Create the "Sobel Edge Detection" button
    GtkWidget *sobel_edge_detection_button = gtk_button_new_with_label("Sobel Edge Detection");

    // Connect the "Sobel Edge Detection" button click signal to the callback function
    g_signal_connect(sobel_edge_detection_button, "clicked", G_CALLBACK(on_sobel_edge_detection_clicked), NULL);

    // Create a box to contain the buttons
    GtkWidget *button_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);

    // Add the buttons to the box
    gtk_box_pack_start(GTK_BOX(button_box), show_image_button, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(button_box), sobel_edge_detection_button, TRUE, TRUE, 0);

    // Add the box to the main window
    gtk_container_add(GTK_CONTAINER(main_window), button_box);

    // Show all widgets in the main window
    gtk_widget_show_all(main_window);

    // Main GTK event loop
    gtk_main();

    return 0;
}
*/



// Function to change the brightness of the image
void change_brightness(GdkPixbuf *pixbuf, int brightness_change) {
    // Get the width, height, and number of channels of the image
    int width = gdk_pixbuf_get_width(pixbuf);
    int height = gdk_pixbuf_get_height(pixbuf);
    int channels = gdk_pixbuf_get_n_channels(pixbuf);

    // Get the pixel data and rowstride
    guchar *pixels = gdk_pixbuf_get_pixels(pixbuf);
    int rowstride = gdk_pixbuf_get_rowstride(pixbuf);

    // Modify the brightness of each pixel
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int c = 0; c < channels; c++) {
                // Calculate the index of the current pixel
                int index = y * rowstride + x * channels + c;
                // Add the brightness_change value to the pixel value and clamp it to the range [0, 255]
                pixels[index] = CLAMP(pixels[index] + brightness_change, 0, 255);
            }
        }
    }
}

// Function to handle when the "Brightness" button is clicked
static void on_brightness_clicked(GtkWidget *button, gpointer data) {
    // Get the parent window
    GtkWidget *parent_window = (GtkWidget *)data;

    // Get the pixbuf from the parent window
    GdkPixbuf *pixbuf = (GdkPixbuf *)g_object_get_data(G_OBJECT(parent_window), "image_pixbuf");

    if (!pixbuf) {
        g_print("Error: No image loaded.\n");
        return;
    }

    // Change the brightness of the image
    change_brightness(pixbuf, 100); // Change brightness by adding 100 to each pixel value

    // Create a new image from the modified pixbuf
    GtkWidget *image_widget = gtk_image_new_from_pixbuf(pixbuf);

    // Create a new window to display the modified image
    GtkWidget *image_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(image_window), "Modified Image");
    gtk_window_set_default_size(GTK_WINDOW(image_window), gdk_pixbuf_get_width(pixbuf), gdk_pixbuf_get_height(pixbuf));
    g_signal_connect(image_window, "destroy", G_CALLBACK(gtk_widget_destroy), NULL);

    // Add the image widget to the new window
    gtk_container_add(GTK_CONTAINER(image_window), image_widget);

    // Show all widgets in the new window
    gtk_widget_show_all(image_window);
}

// Function to handle when the "Load Image" button is clicked
static void on_load_image_clicked(GtkWidget *button, gpointer data) {
    // Get the parent window
    GtkWidget *parent_window = (GtkWidget *)data;

    // Load the image from file into a pixbuf
    GdkPixbuf *image_pixbuf = gdk_pixbuf_new_from_file("/home/agustin/Downloads/LenaMeyer.jpg", NULL);

    if (!image_pixbuf) {
        g_print("Error: Failed to load image.\n");
        return;
    }

    // Store the pixbuf in the parent window
    g_object_set_data(G_OBJECT(parent_window), "image_pixbuf", image_pixbuf);

    // Create a new image widget to display the loaded image
    GtkWidget *image_widget = gtk_image_new_from_pixbuf(image_pixbuf);

    // Create a new window to display the loaded image
    GtkWidget *image_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(image_window), "Loaded Image");
    gtk_window_set_default_size(GTK_WINDOW(image_window), gdk_pixbuf_get_width(image_pixbuf), gdk_pixbuf_get_height(image_pixbuf));
    g_signal_connect(image_window, "destroy", G_CALLBACK(gtk_widget_destroy), NULL);

    // Add the image widget to the new window
    gtk_container_add(GTK_CONTAINER(image_window), image_widget);

    // Show all widgets in the new window
    gtk_widget_show_all(image_window);
}

static void on_load_image_clicked2(GtkWidget *button, gpointer data) {
    // Get the parent window
    GtkWidget *parent_window = (GtkWidget *)data;

    // Create a file chooser dialog
    GtkWidget *dialog = gtk_file_chooser_dialog_new("Open Image", GTK_WINDOW(parent_window), GTK_FILE_CHOOSER_ACTION_OPEN, "Cancel", GTK_RESPONSE_CANCEL, "Open", GTK_RESPONSE_ACCEPT, NULL);

    // Add filters for image formats jpg, png, and bmp
    GtkFileFilter *filter = gtk_file_filter_new();
    gtk_file_filter_set_name(filter, "Image Files");
    gtk_file_filter_add_pattern(filter, "*.jpg");
    gtk_file_filter_add_pattern(filter, "*.png");
    gtk_file_filter_add_pattern(filter, "*.bmp");
    gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(dialog), filter);

    // Run the dialog and get the response
    gint response = gtk_dialog_run(GTK_DIALOG(dialog));

    if (response == GTK_RESPONSE_ACCEPT) {
        // Get the selected filename from the dialog
        char *filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));

        // Load the image from file into a pixbuf
        GdkPixbuf *image_pixbuf = gdk_pixbuf_new_from_file(filename, NULL);

        if (!image_pixbuf) {
            g_print("Error: Failed to load image.\n");
            return;
        }

        // Store the pixbuf in the parent window
        g_object_set_data(G_OBJECT(parent_window), "image_pixbuf", image_pixbuf);

        // Create a new image widget to display the loaded image
        GtkWidget *image_widget = gtk_image_new_from_pixbuf(image_pixbuf);

        // Create a new window to display the loaded image
        GtkWidget *image_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_title(GTK_WINDOW(image_window), "Loaded Image");
        gtk_window_set_default_size(GTK_WINDOW(image_window), gdk_pixbuf_get_width(image_pixbuf), gdk_pixbuf_get_height(image_pixbuf));
        g_signal_connect(image_window, "destroy", G_CALLBACK(gtk_widget_destroy), NULL);

        // Add the image widget to the new window
        gtk_container_add(GTK_CONTAINER(image_window), image_widget);

        // Show all widgets in the new window
        gtk_widget_show_all(image_window);

        // Free the filename string
        g_free(filename);
    }

    // Destroy the dialog
    gtk_widget_destroy(dialog);
}


Mat sobel_edge_detection(const Mat& image) {
    // Convert the input image to grayscale
    Mat grayImage;
    cvtColor(image, grayImage, COLOR_BGR2GRAY);

    // Apply Sobel edge detection to the grayscale image
    Mat edges;
    Sobel(grayImage, edges, CV_8U, 1, 1);



    // Convert the single-channel edge image to a 3-channel image
    Mat output;
    cvtColor(edges, output, COLOR_GRAY2BGR);
    //imshow("output", output);
    //waitKey(0);

    return output;
}

    //GdkPixbuf *edges_pixbuf = 

//gdk_pixbuf_new_from_data(image.data, GDK_COLORSPACE_RGB, FALSE, 8, width, height, rowstride, nullptr, nullptr);

GdkPixbuf* mat_to_pixbuf(const cv::Mat& rgbMat) {
    // Check if the input Mat is empty
    if (rgbMat.empty()) {
        g_print("Error: Input Mat is empty.\n");
        return nullptr;
    }

    std::cout<<"channels "<<rgbMat.channels() <<std::endl;


    //imshow("rgbMat", rgbMat);
    //waitKey(0);

    // Create a GdkPixbuf from the Mat data
    GdkPixbuf *pixbuf = gdk_pixbuf_new_from_data(
        rgbMat.data,                             // Pointer to the image data
        GDK_COLORSPACE_RGB,                     // Colorspace (RGB)
        FALSE,                                  // Whether the image data should be copied
        8,                                      // Bits per sample
        rgbMat.cols,                            // Width of the image
        rgbMat.rows,                            // Height of the image
        rgbMat.step,                            // Rowstride (bytes per row)
        nullptr,                                // Destroy notification function (not used here)
        nullptr                                 // User data (not used here)
    );

    if (!pixbuf) {
        g_print("Error: Failed to create GdkPixbuf from Mat data.\n");
    }

    return pixbuf;
}

static void on_sobel_edge_detection_clicked(GtkWidget *button, gpointer data) {
    // Get the parent window
    GtkWidget *parent_window = (GtkWidget *)data;

    // Get the pixbuf from the parent window
    GdkPixbuf *pixbuf = (GdkPixbuf *)g_object_get_data(G_OBJECT(parent_window), "image_pixbuf");

    if (!pixbuf) {
        g_print("Error: No image loaded.\n");
        return;
    }

    // Convert GdkPixbuf to cv::Mat
    int width = gdk_pixbuf_get_width(pixbuf);
    int height = gdk_pixbuf_get_height(pixbuf);
    int channels = gdk_pixbuf_get_n_channels(pixbuf);
    int rowstride = gdk_pixbuf_get_rowstride (pixbuf);

    Mat image = Mat(height, width, CV_8UC3, gdk_pixbuf_get_pixels(pixbuf), gdk_pixbuf_get_rowstride(pixbuf));

    //Sobel(grayImage, edges, CV_8U, 1, 1);       //1 canal
    //Mat white(height, width, CV_8UC3, Scalar(0,0,255)); //white Mat
    //GaussianBlur(image, image, Size(5, 5), 0);
    //cv::cvtColor(edges, output, COLOR_GRAY2RGB);

    Mat output = sobel_edge_detection(image);

    // Convert the OpenCV Mat image to a GdkPixbuf
    GdkPixbuf *edges_pixbuf = mat_to_pixbuf(output);
    if (!edges_pixbuf) {
        std::cerr << "Error: Failed to convert Mat to GdkPixbuf" << std::endl;
    }


    // Convert the result back to GdkPixbuf
    //GdkPixbuf *edges_pixbuf = gdk_pixbuf_new_from_data(edges.data, GDK_COLORSPACE_RGB, FALSE, 8, width, height, rowstride, nullptr, nullptr);
    //GdkPixbuf *edges_pixbuf = gdk_pixbuf_new_from_data(image.data, GDK_COLORSPACE_RGB, FALSE, 8, width, height, rowstride, nullptr, nullptr);

    // Create a new image widget to display the edges
    GtkWidget *edges_widget = gtk_image_new_from_pixbuf(edges_pixbuf);

    // Create a new window to display the edges
    GtkWidget *edges_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(edges_window), "Sobel Edges");
    gtk_window_set_default_size(GTK_WINDOW(edges_window), width, height);
    g_signal_connect(edges_window, "destroy", G_CALLBACK(gtk_widget_destroy), nullptr);

    // Add the image widget to the new window
    gtk_container_add(GTK_CONTAINER(edges_window), edges_widget);

    // Show all widgets in the new window
    gtk_widget_show_all(edges_window);

    // Clean up edges_pixbuf after edges_window is destroyed
    //g_signal_connect(edges_window, "destroy", G_CALLBACK(g_object_unref), edges_pixbuf);
}

int main(int argc, char *argv[]) {
    // Initialize GTK
    gtk_init(&argc, &argv);

    // Create the main window
    GtkWidget *main_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(main_window), "Main Window");
    gtk_window_set_default_size(GTK_WINDOW(main_window), 200, 100);
    g_signal_connect(main_window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Create the "Load Image" button
    GtkWidget *load_button = gtk_button_new_with_label("Load Image");
    GtkWidget *brightness_button = gtk_button_new_with_label("Change Brightness");
    GtkWidget *sobel_button = gtk_button_new_with_label("Sobel Edge Detection");

    // Connect the "Load Image" button click signal to the callback function
    g_signal_connect(load_button, "clicked", G_CALLBACK(on_load_image_clicked), (gpointer)main_window);

// Connect the "Brightness" button click signal to the callback function
    g_signal_connect(brightness_button, "clicked", G_CALLBACK(on_brightness_clicked), (gpointer)main_window);

    // Connect the "Sobel Edge Detection" button click signal to the callback function
    g_signal_connect(sobel_button, "clicked", G_CALLBACK(on_sobel_edge_detection_clicked), (gpointer)main_window);

    // Create a box to contain the buttons
    GtkWidget *button_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);

    // Add the buttons to the box
    gtk_box_pack_start(GTK_BOX(button_box), load_button, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(button_box), brightness_button, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(button_box), sobel_button, TRUE, TRUE, 0);

    // Add the box to the main window
    gtk_container_add(GTK_CONTAINER(main_window), button_box);

    // Show all widgets in the main window
    gtk_widget_show_all(main_window);

    // Main GTK event loop
    gtk_main();

    return 0;
}
