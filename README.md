# Biblioteca para Display OLED SSD1306 utilizando PICO-SDK

<div align="center">
    <img src="https://github.com/user-attachments/assets/337c76d6-a1cc-414f-bd90-866fe408b844" alt="V-CC_Color_Basica_TextoAzul" style="width:50%;"/>
</div>

## Descrição da Biblioteca
Esta biblioteca foi desenvolvida para um Display OLED SSD1306 para RP2040, via protocolo de comunicação I2C, utilizando o PICO-SDK. Para isso, foi utilizada a plataforma de ensino baseada em tecnologia aberta BitDogLab. Com suporte a gráficos e textos, ela permite criar interfaces visuais eficientes para projetos embarcados.

<div align = "center">
    <img src="https://github.com/user-attachments/assets/17d56731-aa0e-4e26-ae65-f6f476a55f2b" alt="BDL1" style="width:25%;"/> <img src="https://github.com/user-attachments/assets/bcf95a15-ca86-45f4-aeb4-2b736a7ed5b3" alt="BDL2" style="width:25%;">
</div>

## Recursos

- Inicialização e configuração do display SSD1306;
- Controle total de pixels (ligar/desligar); 
- Desenho de formas geométricas (linhas, retângulos, triângulos e círculos);  
- Suporte a fontes customizadas e exibição de texto.    

---

## Dependências

Antes de usar a biblioteca, certifique-se de ter o SDK do Raspberry Pi Pico instalado. O projeto depende das seguintes bibliotecas padrão:

- `hardware/i2c.h` (para comunicação I2C)
- `stdint.h`, `stdlib.h`, `string.h`

---

## 🚀 Instalação

1. Clone este repositório:
   ```sh
   git clone https://github.com/seu-usuario/seu-repositorio.git
