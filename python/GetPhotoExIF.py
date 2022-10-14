# Get Exif of Photo# Method 1
# pip install pillow
import PIL.Image
import PIL.ExifTags
path_name = input("Enter photo name\n")

#img = PIL.Image.open(path_name)
#exif_data = 
#{
#	PIL.ExifTags.TAGS[i]: j
#	for i, j in img._getexif().items()
#	if i in PIL.ExifTags.TAGS
#}
#print(exif_data)

# Method 2
# pip install ExifRead
import exifread

filename = open(path_name, 'rb')

tags = exifread.process_file(filename)
print(tags)
