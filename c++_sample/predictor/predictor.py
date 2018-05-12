import os
import json


class Predictor:
    def __init__(self):
        self.batch_size = 128
        os.system("chmod +x work")

    def predict(self, content):
        f = open("input.txt", "w")
        print(json.dumps(content, ensure_ascii=True), file=f)
        f.close()

        os.system("./work")

        f = open("result.txt", "r")
        result = json.loads(f.readline())
        f.close()

        return result
