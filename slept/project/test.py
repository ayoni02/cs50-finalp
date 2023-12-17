import sys

sys.path.insert(0, '/../../workspaces/105247084/twitter')

from runners import models, preprocess

d = "lbliivjnnsvjgkj.sbnjkdf"



result = models(d)

print(result)
