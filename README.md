# CLI Commands for PowerPoint Project

This project is a simplified recreation of **PowerPoint** that runs entirely through a **Command Line Interface (CLI)**.  
With this approach, presentations are built and controlled using text commands instead of a traditional graphical interface.  
The CLI allows users to create slides, add and format text, insert shapes and images, apply transitions, and manage presentations directly from the terminal.  
This makes it easier to focus on the **core functionality** of a presentation tool while avoiding the complexity of graphical programming.

---

## 1. Slides
- `add.slide.fr` → Create new slide at the front  
- `add.slide.mid` → Create new slide in the middle  
- `add.slide.back` → Create new slide at the back  
- `slide.bg <1,2,3,...>` → Set slide background (choose from options 1,2,3,...)  
- `sw <slide_number>` → Switch between slides  
- `del.slide <slide_number>` → Delete a slide  
- `reorder <old_num> <new_num>` → Reorder slides  

---

## 2. Text
- `add.txt` → Add text  
- `del.txt` → Delete text  
- `edit.txt` → Edit text  
- `select <word>` → Select specific word  
- `bold.txt` → Bold  
- `italic.txt` → Italic  
- `underline.txt` → Underline  
- `font.txt <font_name>` → Set font  
- `color.txt <color>` → Set text color  
- `bg.txt <color>` → Set text background color  
- `size.txt <value>` → Set text size  
- `al.txt.left` → Align left  
- `al.txt.mid` → Align center  
- `al.txt.right` → Align right  

---

## 3. Shapes & Images
- `add.img <path>` → Add image  
- `del.img <image_id>` → Delete image  
- `format.<type>` → Format image (square, circle, etc.)  
- `select.shape <shape id>` → Select specific shape  
- `add.shape <shape>` → Add shape (rectangle, circle, arrow, etc.)  
- `del.shape <shape id>` → Delete shape  
- `size.shape <value>` → Set shape size  
- `color.shape <color>` → Set shape color  

---

## 4. Transitions & Animations
- `add.trans <object_id> <type>` → Add transition to slide  
- `add.anim <object_id> <type>` → Add animation to text/shape/image
- `del.trans <slide_number>` → Remove transition
- `del.anim <object_id>` → Remove animation
- `del.anim <object_id>` → Remove animation
 
---

## 5. Presentation Control
- `start.present` → Begin slideshow
- `next.slide` → Go to next slide
- `prev.slide` → Go to previous slide
- `end.present` → Exit slideshow

---

## 6. File Operations
- `save <file_name>` → Save presentation
- `save` → Save progress
- `open <file_name>` → Open saved presentation
- `export <file_name> <file_type>` → Export file
- `help` → Show list of commands
- `exit` → Quit program
