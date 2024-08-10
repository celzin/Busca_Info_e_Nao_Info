<div align="center" style="display: inline_block">
  <img align="center" alt="VS" src="https://img.shields.io/badge/Visual_Studio_Code-0078D4?style=for-the-badge&logo=visual%20studio%20code&logoColor=white" />
  <img align="center" alt="Linux" src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black" />
  <img align="center" alt="C++" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" />
</div>

<br>
<!-- <h1 align="center">
    <a>
        <img alt="Banner" title="#Banner" style="object-fit: fill; width: 961px, height:200px;" src="imgs/github-header-image.png"/>
    </a>
</h1> -->

## 🗂️ Estrutura do Repositório

- `report/`: Diretório contendo o relatório do projeto em formato LaTeX.
- `src/`: Diretório com os scripts C++ usados para gerar os percursos do agente e realizar as análises.
- `imgs/`: Diretório com as imagens utilizadas no repositório.

## 📝 Resumo

<p align="center">
<img src="imgs/Busca_Info_e_Não_Info.png" width="800"/> 
</p>
<p align="center">
<em>Figura 1: Imagem ilustrativa das configurações dos 3 cenários utilizados nas análises. </em>
</p>

<div align="justify">
Este projeto foca na implementação e comparação de diferentes algoritmos de busca aplicados ao problema do labirinto, utilizando a linguagem de programação C++. Os algoritmos são avaliados em termos de tempo de execução, consumo de memória, completude e optimalidade, proporcionando uma análise abrangente de suas eficiências. A seguir, é discutida a metodologia utilizada para desenvolver e testar esses algoritmos. A implementação abrange dois algoritmos de busca não informada (Busca em Largura - <code>BFS</code> e Busca em Profundidade - <code>DFS</code>) e dois algoritmos de busca informada (<code>A*</code> e Busca Gulosa - <code>GBFS</code>).
</div>

## 🔄 Compilação e Execução 

<div align="justify">

Esse programa possui um arquivo (`Makefile`) e um (`CMakeLists`), os quais realizam todo o procedimento de compilação e execução. Para tanto, cabe ao usuário escolher o de sua preferência, porém se atente ao fato de que para cada um temos as seguintes diretrizes de execução:

</div>

### Makefile

<table align="center">
  <tr>
    <th>Comando</th>
    <th>Função</th>
  </tr>
  <tr>
    <td>make clean</td>
    <td>Apaga a última compilação realizada contida na pasta build</td>
  </tr>
  <tr>
    <td>make</td>
    <td>Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build</td>
  </tr>
  <tr>
    <td>make run</td>
    <td>Executa o programa da pasta build após a realização da compilação</td>
  </tr>
</table>
	
### CMake

<table align="center">
  <tr>
    <th>Comando</th>
    <th>Função</th>
  </tr>
  <tr>
    <td>cmake -B ./build</td>
    <td>Cria as instâncias da pasta build necessárias para execução do programa</td>
  </tr>
  <tr>
    <td>cmake --build ./build</td>
    <td>Executa a compilação do programa utilizando o cmake, e o resultado vai para a pasta build</td>
  </tr>
  <tr>
    <td>./build/app</td>
    <td>Executa o programa da pasta build após a realização da compilação</td>
  </tr>
</table>

## 📞 Contato

<table align="center">
  <tr>
    <th>Participante</th>
    <th>Contato</th>
  </tr>
  <tr>
    <td>Celso</td>
    <td><a href="https://t.me/celso_vsf"><img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/> </td>
  </tr>
</table>