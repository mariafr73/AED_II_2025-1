import pandas as pd
import matplotlib.pyplot as plt

# Carregar os dados corretamente, ignorando cabeçalhos desnecessários
df = pd.read_csv("dados.csv", skiprows=1, names=["n", "Recursivo", "Iterativo", "Formula"])

# Converter colunas para números
df["n"] = pd.to_numeric(df["n"], errors="coerce")
df["Recursivo"] = pd.to_numeric(df["Recursivo"], errors="coerce")
df["Iterativo"] = pd.to_numeric(df["Iterativo"], errors="coerce")
df["Formula"] = pd.to_numeric(df["Formula"], errors="coerce")

# Função para gerar gráficos individuais
def gerar_grafico(coluna, titulo, nome_arquivo, cor, estilo):
    plt.figure(figsize=(10, 5))
    plt.plot(df["n"], df[coluna], estilo, label=coluna, color=cor)
    plt.xlabel("Valor de n")
    plt.ylabel("Tempo médio (segundos)")
    plt.title(titulo)
    plt.legend()
    plt.grid()
    plt.savefig(nome_arquivo)
    print(f"✅ Gráfico '{nome_arquivo}' gerado com sucesso!")

# Gerar gráficos individuais para cada versão
gerar_grafico("Recursivo", "Algoritmo Otimizado 1 – Manutenção da Recursão", "grafico_recursivo.png", "blue", "o-")
gerar_grafico("Iterativo", "Algoritmo Otimizado 2 – Eliminação da Recursão", "grafico_iterativo.png", "green", "s-")
gerar_grafico("Formula", "Algoritmo Otimizado 3 – Fórmula Fechada", "grafico_formula.png", "red", "x-")

print("🟢 Processo concluído! Todos os gráficos foram gerados corretamente.")