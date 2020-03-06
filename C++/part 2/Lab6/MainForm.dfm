object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Password Encrypt'
  ClientHeight = 201
  ClientWidth = 447
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object label: TLabel
    Left = 0
    Top = 0
    Width = 447
    Height = 24
    Align = alTop
    Alignment = taCenter
    Caption = 'Enter Password'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    Layout = tlCenter
    ExplicitWidth = 137
  end
  object StackPanel1: TStackPanel
    Left = 0
    Top = 24
    Width = 447
    Height = 177
    Align = alClient
    ControlCollection = <
      item
        Control = ComboBox1
        HorizontalPositioning = sphpFill
        VerticalPositioning = spvpFill
      end
      item
        Control = Edit1
        HorizontalPositioning = sphpFill
        VerticalPositioning = spvpFill
      end
      item
        Control = Button1
        HorizontalPositioning = sphpFill
        VerticalPositioning = spvpTop
      end
      item
        Control = LabelResult
        HorizontalPositioning = sphpFill
        VerticalPositioning = spvpBottom
      end>
    TabOrder = 0
    object ComboBox1: TComboBox
      Left = 1
      Top = 1
      Width = 445
      Height = 21
      Align = alClient
      ItemIndex = 0
      TabOrder = 0
      Text = 'Encrypt'
      OnChange = ComboBox1Change
      Items.Strings = (
        'Encrypt'
        'Decrypt')
    end
    object Edit1: TEdit
      AlignWithMargins = True
      Left = 4
      Top = 27
      Width = 439
      Height = 21
      Align = alClient
      Alignment = taCenter
      PasswordChar = '#'
      TabOrder = 1
    end
    object Button1: TButton
      Left = 1
      Top = 53
      Width = 445
      Height = 25
      Align = alTop
      Caption = 'Process'
      TabOrder = 2
      OnClick = Button1Click
    end
    object LabelResult: TLabel
      Left = 1
      Top = 80
      Width = 445
      Height = 13
      Margins.Top = 20
      Align = alBottom
      Alignment = taCenter
      DragMode = dmAutomatic
      Layout = tlBottom
    end
  end
end
