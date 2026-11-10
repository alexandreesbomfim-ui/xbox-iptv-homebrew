# IPTV360 – gerenciador de playlists M3U para Xbox 360

Homebrew em C++ para **libxenon** (Free60). Gera `iptv360.elf32`, que roda via **XeLL**
em console com RGH/JTAG (ou via BadUpdate + FreeMyXe → XeLL).

> Nao gera `.xex`. XEX exige o XDK da Microsoft (proprietario) ou o SynthXEX/FreeChainXenon
> (em desenvolvimento, ainda sem "exports"). Veja a resposta no chat.

## Compilar (recomendado: Docker)
    docker run -it -v $PWD:/app free60/libxenon:latest
    cd /app && make          # gera iptv360.elf32

## Compilar (GitHub Actions)
Basta dar push: `.github/workflows/build.yml` compila dentro de `free60/libxenon:latest`
e publica o artefato `iptv360-xbox360`.

## Usar
Copie `iptv360.elf32` e `playlist.m3u` para o pendrive (FAT32) e execute pelo XeLL.
A playlist e procurada em `<dispositivo>:/playlist.m3u`, `iptv360/playlist.m3u` e `playlist.m3u8`.

Controles: D-pad/analogico = navegar · LB/RB = pagina · A = detalhes · Y = filtrar grupo ·
B = recarregar · Logo = sair.

## Status
- [x] Parser M3U (BOM, CRLF, virgula dentro de aspas, group-title) – testado no PC (`tests/`)
- [x] Interface por console + controle
- [ ] Reproducao de video: libxenon nao traz decodificador H.264/AAC nem sockets BSD/DNS
      (lwIP em modo NO_SYS, LWIP_SOCKET=0). E a parte grande do projeto.
