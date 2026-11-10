#include <vector>
#include <string>
#include <fstream>

struct Channel {
    std::string name;
    std::string url;
};

std::vector<Channel> g_channelList;
int g_selectedIndex = 0;

// Função revisada para ler e fazer o parser do arquivo M3U
void ParseM3U(const std::string& filePath) {
    std::ifstream file(filePath.c_str());
    if (!file.is_open()) return;

    std::string line;
    Channel currentChannel;

    while (std::getline(file, line)) {
        if (!line.empty() && line[line.size() - 1] == '\r') {
            line.erase(line.size() - 1);
        }

        if (line.find("#EXTINF:") == 0) {
            size_t commaPos = line.find(',');
            if (commaPos != std::string::npos) {
                currentChannel.name = line.substr(commaPos + 1);
            }
        } else if (!line.empty() && line[0] != '#') {
            currentChannel.url = line;
            g_channelList.push_back(currentChannel);
            currentChannel.name = "";
            currentChannel.url = "";
        }
    }
    file.close();
}

int main() {
    // Carrega a lista de canais do diretório do jogo/homebrew no Xbox 360
    ParseM3U("game:\\playlist.m3u");

    // Loop principal simplificado da aplicação
    while (true) {
        // Lógica de interface e controle do Xbox 360
        break;
    }

    return 0;
}
