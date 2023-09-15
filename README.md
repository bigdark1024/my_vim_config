# MY_VIM_CONFIG
My personal vim config.

# OS PLATFORM
Ubuntu 18.0+

# PREINSTALL
```shell
sudo apt install nvim
sudo apt install ccls
sudo apt install ranger

// install lazygit
sudo add-apt-repository ppa:lazygit-team/release
sudo apt-get update
sudo apt-get install lazygit
sudo apt install -y ripgrep
```

# INSTALL
git clone git@github.com:bigdark1024/my_vim_config.git ~/.config/nvim

OR

git clone https://github.com/bigdark1024/my_vim_config.git ~/.config/nvim

Execute PlugInstall to install the plugins.


## FAQ

- No "python3" provider found. Run ":checkhealth provider"

> https://neovim.io/doc/user/provider.html

```text
python3 -m pip install --user --upgrade pynvim
pip3 install --user --upgrade neovim
```
