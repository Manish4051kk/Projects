class Rectangle:
  def __init__(self, width, height):
    self.height = height
    self.width = width

  def __repr__(self):
    return f"Rectangle(width={self.width}, height={self.height})"

  def set_width(self, width):
    self.width = width

  def set_height(self, height):
    self.height = height

  def get_area(self):
    return self.width * self.height

  def get_perimeter(self):
    return (2 * self.width) + (2 * self.height)

  def get_diagonal(self):
    return ((self.width ** 2) + (self.height ** 2)) ** .5

  def get_picture(self):
    if self.width > 50 or self.height > 50:
      return "Too big for picture."

    s = ""
    for row in range(self.height):
      s += "*" * self.width + "\n"
    return s

  def get_amount_inside(self, shape):
    i_area = shape.height * shape.width
    r_area = self.get_area()
    return r_area // i_area


class Square(Rectangle):
  def __init__(self, side):
    super().__init__(side, side)

  def __repr__(self):
    return f"Square(side={self.width})"

  def set_side(self, side):
    self.width = side
    self.height = side

  def set_width(self, side):
    self.set_side(side)

  def set_height(self, side):
    self.set_side(side)
