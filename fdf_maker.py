# -*- coding: utf-8 -*-
from PIL import Image, ImageFilter
import numpy as np

img = Image.open("cyber.PNG")
img = img.convert("L")
img = img.filter(ImageFilter.GaussianBlur(radius=2.5))
img = img.resize((256, 256))  # tamaño final
pixels = np.array(img)

with open("cyber02.fdf", "w") as f:
    for row in pixels:
        f.write(" ".join(str(val) for val in row) + "\n")
