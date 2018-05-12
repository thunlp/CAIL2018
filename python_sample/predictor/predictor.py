class Predictor:
    def __init__(self):
        self.batch_size = 128

    def predict(self, content):
        result = []
        for a in range(0, len(content)):
            result.append({
                "accusation": [1, 2, 3],
                "imprisonment": 5,
                "articles": [5, 7, 9]
            })
        return result
