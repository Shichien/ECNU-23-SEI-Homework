#  pip install openai==0.28
# 注意下方代码必须使用该版本
import openai

def query_gpt4(question):
    openai.api_key = ""
    openai.api_base = ""

    try:
        response = openai.ChatCompletion.create(
            model="gpt-4o-all",
            messages=[
                {"role": "system", "content": "You are a helpful assistant."},
                {"role": "user", "content": question}
            ]
        )
        return response['choices'][0]['message']['content']
    except Exception as e:
        return str(e)

question = "Are you GPT-4o?"

answer = query_gpt4(question)
print(answer)

