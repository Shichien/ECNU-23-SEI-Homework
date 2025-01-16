import requests

API_URL = "https://chat.ecnu.edu.cn/open/api/v1/chat/completions"
API_HEADERS = {
    "Authorization": "Bearer sk-d0e0ea88aea4417dbd740d36edd4e6ad",
    "Content-Type": "application/json"
}

# 验证诗句是否符合规则
def validate_poem(poem, keyword):
    if keyword in poem:
        return True
    return False

def ai_response(keyword, user_poem):
    prompt = (f"我们正在玩飞花令游戏，"
              f"关键词是'{keyword}'。我刚才的诗句是：'{user_poem}'，"
              f"请你分析这句诗是否存在，如果不存在，请你告诉我我输了。"
              f"如果这句诗存在，\n请帮我接下一个包含关键词'{keyword}'的诗句，并返回整句诗：")

    data = {
        "model": "ecnu-plus",
        "messages": [
            {"role": "system", "content": "You are a helpful assistant and an expert in classical Chinese poetry."},
            {"role": "user", "content": prompt}
        ],
        "search_mode": "enable"
    }

    response = requests.post(API_URL, headers=API_HEADERS, json=data)
    if response.status_code == 200:
        reply = response.json().get("choices")[0].get("message").get("content")
        return reply.strip()

# 主程序
def main():
    print("欢迎进入飞花令游戏！")
    print("1. 每轮输入一首包含关键词的诗句；")
    print("2. 如果你无法回答或回答不符合规则，AI 将获胜！\n")

    keyword = input("请输入游戏的关键词：").strip()
    print(f"关键词是：'{keyword}'，游戏开始！\n")
    user_turn = True  # 用户先手

    # 游戏循环
    last_poem = None  # 上一首诗句
    while True:
        if user_turn:
            user_input = input(f"请输入一首包含关键词'{keyword}'的诗句：").strip()
            if user_input.lower() == "exit":
                print("游戏结束！感谢参与！")
                break

            # 验证用户输入
            if validate_poem(user_input, keyword):
                print(f"你的诗句：{user_input}")
                last_poem = user_input
                user_turn = False  # 轮到 AI
            else:
                print(f"你的诗句不包含关键词'{keyword}'，你输了！")
                break
        else:
            # AI 应答
            ai_poem = ai_response(keyword, last_poem)
            if ai_poem and validate_poem(ai_poem, keyword):
                print(f"AI 的诗句：{ai_poem}")
                last_poem = ai_poem
                user_turn = True  # 轮到用户
            else:
                print("AI 无法继续接龙，你赢了！")
                break

if __name__ == "__main__":
    main()
