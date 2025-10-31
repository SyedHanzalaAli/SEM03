class Image:
    def __init__(self , pixelData):
        self.pixels = pixelData
    
    def getCopy(self):
        copyPixels = []
        for row in self.pixels:
            newRow = []
            for value in row:
                newRow.append(value)
            copyPixels.append(newRow)
        return copyPixels
    
    def applyTransformation(self, transformationFunc):
        self.pixels = transformationFunc(self.pixels)
    
def flipHorizontal(pixelData):
    newPixels = []
    for row in pixelData:
        newRow = []
        for value in reversed(row):
            newRow.append(value)
        newPixels.append(newRow)
    return newPixels

def adjustBrightness(pixelData , brightnessValue):
    newPixels = []
    for row in pixelData:
        newRow = []
        for value in row:
            newRow.append(value + brightnessValue)
        newPixels.append(newRow)
    return newPixels

def rotateNinetyDegrees(pixelData):
    rows = len(pixelData)
    cols = len(pixelData[0])
    newPixels = []
    for i in range(cols):
        newRow = []
        for j in range(rows):
            newRow.append(pixelData[rows-j-1][i])
        newPixels.append(newRow)
    return newPixels

class AugmentationPipeline:
    def __init__(self):
        self.steps = []

    def addstep(self , transformFunc):
        self.steps.append(transformFunc)
    
    def processImage(self , originalImage):
        augmentedImages = []
        for func in self.steps:
            newImage = Image(originalImage.getCopy())
            newImage.applyTransformation(func)
            augmentedImages.append(newImage)
        return augmentedImages
    
if __name__ == "__main__":
    originalPixels = [
        [10,20,30],
        [40,50,60]
    ]

    img = Image(originalPixels)
    pipeline = AugmentationPipeline()
    pipeline.addstep(flipHorizontal)
    pipeline.addstep(lambda pixels : adjustBrightness(pixels,10))
    pipeline.addstep(rotateNinetyDegrees)

    results = pipeline.processImage(img)

    print("Original:")
    for row in img.pixels:
        print(row)

    print("\nAugmented Images:")
    for idx, image in enumerate(results, start=1):
        print(f"Image {idx}:")
        for row in image.pixels:
            print(row)
        print()