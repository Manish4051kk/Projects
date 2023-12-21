import copy
import random


class Hat:
  def __init__(self, **kwargs):
    self.contents = []
    for k, v in kwargs.items():
      self.contents += v * [k]

  def draw(self, num):
    try:
      balls = random.sample(self.contents, num)
    except:
      balls = copy.deepcopy(self.contents)

    for ball in balls:
      self.contents.remove(ball)

    return balls


def experiment(hat, expected_balls, num_balls_drawn, num_experiments):
  M = 0
  for i in range(num_experiments):
    hat_copy = copy.deepcopy(hat)
    balls = hat_copy.draw(num_balls_drawn)

    eb_list = []
    for k, v in expected_balls.items():
      eb_list += v * [k]

    if contains_balls(eb_list, balls):
      M += 1

  probability = M / num_experiments
  return probability


def contains_balls(exptected_balls, actual_balls):
  for b in exptected_balls:
    if b in actual_balls:
      actual_balls.remove(b)
    else:
      return False
  return True
