#Resumo
O objetivo desse trabalho é aplicar as técnicas de programação aprendidas nas disciplinas de
PTP e ITP em uma situação prática. A esteganografia é o fato de esconder mensagens nas imagens,
e a partir das práticas desenvolvidas em sala foi possível desenvolver um programa capaz de
encriptar e decriptar mensagens em imagens.

Esteganografia é uma técnica utilizada a muitos anos, e ela basicamente consiste em
esconder mensagens em imagens, ou em textos. Em imagens digitais, a esteganografia consiste em
esconder informações nos bytes de informações, e para isso é utilizada a tabela ASCII onde cada
caractere tem sua semelhança númerica.

Nesse trabalho, a técnica de esteganografia que será desenvolvida é a do bit menos
significativo. A ideia dessa técnica é encriptar uma mensagem, modificando apenas o ultimo bit dos
pixels da imagem.

Cada caractere na tabela ASCII possui 8 Bits, ou seja 1 Byte de informação. Com isso para
armazenar uma letra seriam necessários 8 Bytes de informação na imagem pois seria alterado
apenas o ultimo bit de cada imagem. Foram utilizadas imagens coloridas com 24 bits nesse trabalho,
nos formatos PPM e BMP e todo o código deveria ser escrito na linguagem C.

Biblioteca pxx.h
PX : um enum que tinha valores P1,P2,P3,P4,P5,P6 partindo do 1. Esse enum foi criado para
facilitar e tornar o código mais legivel quando fosse verificado o tipo da imagem.
PXX: uma struct que serviria como uma estrutura mãe para todos os tipos de PPM, a ideia
era criar uma hierarquia para as estruturas PPM.
GREY: é uma struct que armazenaria um byte em imagens preto e branco ou com tons de
cinza.
RGB : é uma struct que armazenaria 3 bytes das imagens coloridas.
PBM: uma struct voltada para armazenar o tipo PBM.
PGM: uma struct voltada para armazenar o tipo PGM.
PPM: uma struct voltada para armazenar o tipo PPM.

Biblioteca converter.h
Biblioteca voltada para a conversão de inteiros para cadeias de caracteres binárias. Essa
biblioteca é fundamental na hora da encriptação da informação pois através da função decToBin é
possível converter o valor inteiro do caractere para bits.

Biblioteca leiturappm.h
Essa biblioteca é fundamental para a encriptação do programa, como foi dito mais acima eu
criei todo o programa para leitura, encriptação e desencriptação do PPM para depois fazer a parte
do BMP, portanto essa biblioteca no começo tinha a função de encriptação e desencriptação.
Após a criação das bibliotecas básicas era necessário escrever um código de leitura do
arquivo .PPM, para isso haviam diversas formas de leitura. Na leiturappm.h existe uma função
chamada readPXX, essa função é responsável por ler o formato da imagem PPM (P1,P2,P3…), o
tamanho da imagem e caso ela seja colorida ou grey o maior valor de bits, isso é considerado o
cabeçalho das imagens do tipo PPM. Em seguida a essa leitura ela chama a função readP6 (no
trabalho só será utilizada o tipo P6) que lê os bits da imagem na struct criada para armazenamento.
Como na classe PPM existe um RGB ** então é necessário alocar dinamicamente o ponteiro, para
isso é utilizada a função malloc para alocar o tamanho das linhas e colunas de pixels no RGB. Após
isso foi utilizada a leitura dos bytes através da função fgetc, com isso torna-se possível popular a
estrutura do PPM.

Em seguida era necessário ler a mensagem a ser criptografada, para isso foi criado uma
função chamada getMessage, que recebe o nome do ficheiro a ser explorado e retorna todo o
conteúdo do ficheiro como um char . A alocação foi feita através da varredura de todo o arquivo
contando a quantidade de caracteres e em seguida reseta para posição inicial do arquivo atraves da
função rewind e em seguida aloca a mensagem do tamanho desejado e lê-a.

Encriptação
Para encriptação em um primeiro momento utilizei operações de resto de divisão, porém o
código ficou bastante confuso e ineficiente. Em seguida, usei as operações de bitwise para eliminar
o ultimo bit do pixel da imagem e acrescentar a ele o valor do digito convertido na função decToBin
. Essa função recebia cada digito de cada palavra e convertia esse digito para binário e esses valores
binários era operados para entrar na imagem. Como a função decToBin retorna um tipo char, ela
retorna o caractere númerico 1 ou 0 por isso a necessidade de subtrair o valor 48 do digit[j]. Então
basicamente a operação era usar a máscara 11111110 para eliminar o ultimo bit do componente do
pixel da imagem e em seguida acrecer o valor do bit da letra.

Desencriptação
A desencriptação da imagem é basicamente o processo inverso do anterior, verificar o ultimo
bit e utilizar de potências de base 2 para conseguir o valor decimal do caractere. Portanto a função
decript basicamente verificava se um o bit era divisivel por 2, se sim ele tinha ultimo bit igual a 0 se
não ele tinha o ultimo bit igual a 1. Outra forma possível é através de uma máscara inversa a
anterior, essa mascara deveria isolar apenas o ultimo bit portanto o seu valor deveria ser 00000001
dessa forma com a operação & teria apenas o ultimo bit.

BMP
Para o BMP eu utilizei os mesmos conceitos do PPM, a grande diferença do BMP para o
PPM é a leitura do arquivo que deve ser ao contrário, por isso a única informação que precisava
realmete ser convertida foram as dimensões da imagem. Eu passei bastante tempo tentando fazer
funcionar com a leitura convencional, o grande problema que dava era gerar arquivos gigantes e que
não alteravam a forma da imagem, após um tempo descobri que o programa estava escrevendo mais
do que o que devia e a imagem ficava muito grande, porém como a leitura depende dos tamanhos
ditos no arquivo, após esses tamanhos toda a informação era ignorada onde a imagem era exibida.
Dessa forma, criei uma função para reverter os bytes da imagem através de bitwise. Ela
basicamente pega o ultimo byte lido e transforma no primeiro de forma a inverter os bytes do
inteiro. Com isso, o programa pode funcionar e a leitura dessa vez ao invés de usar o fgetc que é
uma função muito demorada, foi utilizado o fread, e a largura e comprimento que são necessários
para o programa,pois sem eles não daria para alocar o RGB, foi usado fseek para setar a posição
tendo em vista o BMP ter um cabeçalho fixo e depois a função que lê invertido.

Bibliografia
1. PHILIPS, Dwane. Image Processing in C. 2nd Edition. Lawrence: R &D Publications, 1994.
1. LOPES, João Manuel Brisson. Formatos de Imagem. 2003. Disponível em:
http://disciplinas.ist.utl.pt/~leic-cg.daemon/textos/livro/Formatos%20de%20Imagem.pdf. Acesso
em 25/06/2017.