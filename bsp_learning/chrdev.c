#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h> // For copy_to_user and copy_from_user

#define DEVICE_NAME "chardev"
#define BUF_LEN 80

static int major_number;
static int device_open_count = 0;
static char message[BUF_LEN] = "Hello, World!";
static char *message_ptr;

// Function prototypes
static int device_open(struct inode *, struct file *);
static int device_release(struct inode *, struct file *);
static ssize_t device_read(struct file *, char __user *, size_t, loff_t *);
static ssize_t device_write(struct file *, const char __user *, size_t, loff_t *);

// File operations structure
static struct file_operations fops = {
.read = device_read,
.write = device_write,
.open = device_open,
.release = device_release
};

// Module initialization
static int __init chardev_init(void) {
major_number = register_chrdev(0, DEVICE_NAME, &fops);
if (major_number < 0) {
printk(KERN_ALERT "Failed to register character device\n");
return major_number;
}
printk(KERN_INFO "Character device registered with major number %d\n", major_number);
return 0;
}

// Module cleanup
static void __exit chardev_exit(void) {
unregister_chrdev(major_number, DEVICE_NAME);
printk(KERN_INFO "Character device unregistered\n");
}

// Open function
static int device_open(struct inode *inode, struct file *file) {
if (device_open_count > 0) {
return -EBUSY;
}
device_open_count++;
message_ptr = message;
try_module_get(THIS_MODULE);
return 0;
}

// Release function
static int device_release(struct inode *inode, struct file *file) {
device_open_count--;
module_put(THIS_MODULE);
return 0;
}

// Read function
static ssize_t device_read(struct file *filp, char __user *buffer, size_t length, loff_t *offset) {
int bytes_read = 0;
if (*message_ptr == 0) {
return 0; // End of message
}
while (length && *message_ptr) {
put_user(*(message_ptr++), buffer++);
length--;
bytes_read++;
}
return bytes_read;
}

// Write function
static ssize_t device_write(struct file *filp, const char __user *buffer, size_t length, loff_t *offset) {
printk(KERN_ALERT "Write operation is not supported\n");
return -EINVAL;
}

module_init(chardev_init);
module_exit(chardev_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple Linux character device driver")
